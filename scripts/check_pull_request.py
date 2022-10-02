import os
import argparse
import subprocess
import requests
from bs4 import BeautifulSoup as bs
from glob import glob

# 확장자, 버전, 언어, 솔루션 파일 명, 컴파일, 실행
LANGUAGE_INFO = {
    "python": ["py", "python", "main", None, "python3 {} < example.in"],
    "cpp20": ["cpp", "cpp20", "main", "g++ {} -o Main -O2 -Wall -lm -std=gnu++2a", "./Main < example.in"],
    "cpp17": ["cpp", "cpp17", "main", "g++ {} -o Main -O2 -Wall -lm -std=gnu++17", "./Main < example.in"],
    "cpp14": ["cpp", "cpp14", "main", "g++ {} -o Main -O2 -Wall -lm -std=gnu++14", "./Main < example.in"],
    "java15": ["java", "java15", "Main", "javac --release 15 -J-Xms1024m -J-Xmx1920m -J-Xss512m -encoding UTF-8 {} -d .", "java -Xms1024m -Xmx1920m -Xss512m -Dfile.encoding=UTF-8 -XX:+UseSerialGC Main < example.in"],
    "java11": ["java", "java11", "Main", "javac --release 11 -J-Xms1024m -J-Xmx1920m -J-Xss512m -encoding UTF-8 {} -d .", "java -Xms1024m -Xmx1920m -Xss512m -Dfile.encoding=UTF-8 -XX:+UseSerialGC Main < example.in"],
    "java8": ["java", "java8", "Main", "javac --release 8 -J-Xms1024m -J-Xmx1920m -J-Xss512m -encoding UTF-8 {} -d .", "java -Xms1024m -Xmx1920m -Xss512m -Dfile.encoding=UTF-8 -XX:+UseSerialGC Main < example.in"],
    "rust2021": ["rs", "rust2021", "main", "rustc --edition 2021 -O -o Main {}", "./Main < example.in"],
    "rust2018": ["rs", "rust2018", "main", "rustc --edition 2018 -O -o Main {}", "./Main < example.in"],
    "rust2015": ["rs", "rust2015", "main", "rustc --edition 2015 -O -o Main {}", "./Main < example.in"],
    "c2x": ["c", "c2x", "main", "gcc -std=gnu2x {} -o Main", "./Main < example.in"],
    "c11": ["c", "c11", "main", "gcc -std=gnu11 {} -o Main", "./Main < example.in"],
    "kotlin": ["kt", "kotlin", "main", "kotlinc-jvm -J-Xms1024m -J-Xmx1920m -J-Xss512m -include-runtime -d Main.jar {}", "java -Xms1024m -Xmx1920m -Xss512m -Dfile.encoding=UTF-8 -XX:+UseSerialGC -jar Main.jar < example.in"],
    "node": ["js", "node", "main", None, "node --stack-size=65536 {}"],
    "swift": ["swift", "swift", "main", "swiftc -O -o Main {}", "./Main < example.in"], 
    "go": ["go", "go", "main", "go build -o Main {}", "./Main < example.in"]
}
LABEL_INFO = {
    "c": "C", "python": "Python", "java": "Java",
    "rust": "Rust", "go": "Go", "node": "Node.js",
    "cpp": "C++", "kotlin": "Kotlin", "swift":"Swift"
}
EXTENSION_INFO = {"py": "python", "rs": "rust", "js": "node"}
LANGUAGE_VERSION = {}
for key, value in LANGUAGE_INFO.items():
    extension = EXTENSION_INFO.get(value[0], value[0])
    LANGUAGE_VERSION[extension] = LANGUAGE_VERSION.get(extension, [])
    LANGUAGE_VERSION[extension].append(value[1])


def run_command(cmd):
    return subprocess.check_output(cmd, shell=True).decode('utf8')


def get_pr_files(pr_number):
    cmd = f"git fetch origin +refs/pull/{pr_number}/merge"
    run_command(cmd) 
    cmd = f"git --no-pager diff --name-only FETCH_HEAD $(git merge-base FETCH_HEAD main)"
    files = [file.strip() for file in run_command(cmd).split() if file.strip() != ""]
    return files


def detect_tab(path):
    with open(path, 'r') as f:
        solution = f.readlines()
        f.close()

    for line in solution:
        if '\t' in line:
            raise Exception("Detected Tab in this solution")

    print("No Detect Tab")


def get_example(problem_id):
    url = f"https://www.acmicpc.net/problem/{problem_id}"
    req = requests.get(url)
    html = bs(req.text, 'html.parser')
    spj = True if html.find('span', 'problem-label-spj') else False
    if spj:
        print("Found Special Judge")

    examples = []
    try:
        sample_id = 1
        while True:
            sample_input = html.select(f'#sample-input-{sample_id}')[0].text
            sample_output = html.select(f'#sample-output-{sample_id}')[0].text
            examples.append((sample_input, sample_output))
            sample_id += 1
    except:
        pass
    return spj, examples


def check_output(x, y):
    idx1, idx2 = 0, 0
    N, M = len(x), len(y)
    while True:
        while idx1 < N and (x[idx1] == ' ' or x[idx1] == '\r' or x[idx1] == '\n'): idx1 += 1
        while idx2 < M and (y[idx2] == ' ' or y[idx2] == '\r' or y[idx2] == '\n'): idx2 += 1
        if idx1 >= N or idx2 >= M: break
        if x[idx1] != y[idx2]: return False
        idx1, idx2 = idx1 + 1, idx2 + 1
    return True


def analyze(path):
    filename, extension = path.split('/')[-1].split('.')
    language = EXTENSION_INFO.get(extension, extension)
    with open('label', 'w') as f:
        f.write(LABEL_INFO.get(language))
        f.close()


def judge(path):
    filename, extension = path.split('/')[-1].split('.')
    flag = False
    problem = path.split('/')[-2]
    language = EXTENSION_INFO.get(extension, extension)
    spj, samples = get_example(problem)
    if LANGUAGE_VERSION.get(language, None) == None:
        raise Exception(f"{language} Not Found.")
    for version in LANGUAGE_VERSION.get(language):
        info = LANGUAGE_INFO.get(version)
        if info[3] != None: 
            try: 
                run_command(info[3].format(path))
            except:
                continue
        flag = True
        print(f"{version} OK")
        if spj: # TODO
            return True
        for idx, (data_input, data_output) in enumerate(samples):
            with open('example.in', 'w') as f:
                f.write(data_input)
                f.close()
            result = run_command(info[4].format(path)).rstrip()
            data_output = data_output.rstrip()
            if not check_output(result, data_output):
                return False
        if flag:
            return True


def check_alreay_exist_solution(path):
    if os.path.exists(path):
        raise Exception("Alread Exists Solution")

    print("It is a new Solution!!")


def main(pr_number, only_language=False):
    files = get_pr_files(pr_number)
    if len(files) > 1:
        raise Exception("No 1 PR 1 File")
    if only_language:
        analyze(files[0])
        return
    run_command(f"git checkout FETCH_HEAD") 
    check_alreay_exist_solution(files[0])
    judge_result = judge(files[0])
    if not judge_result:
        raise Exception("Wrong Example")
    print("Accepted")


def load_arg():
    parser = argparse.ArgumentParser()
    arg = parser.add_argument
    arg('--pr_number', type=int, required=True, help="Pull Request Number")
    arg('--check_language', action='store_true')
    parser.set_defaults(check_language=False)
    return parser.parse_args()


if __name__=="__main__":
    args = load_arg()
    main(args.pr_number, args.check_language)
