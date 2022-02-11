#! /bin/python3.10

import argparse
import os.path
import sys

import multisetlib as msl


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Find union of two multisets")
    parser.add_argument('files', type=str, nargs='+', help="files of sets")
    return parser.parse_args()


def check_args(args: argparse.Namespace) -> bool:
    result = True
    for file in args.files:
        result = result and os.path.isfile(file)
    return result


def read_file(path: str):
    with open(path) as file:
        return file.read()


def get_multiset_math_form(mset, _first=True):

    result = ""

    if type(mset) not in [msl.Multiset, tuple]:
        result += str(mset) + ','

    if type(mset) is msl.Multiset:
        result += '{'
        for element in mset:
            result += get_multiset_math_form(element, _first=False)
        result += '},'

    if type(mset) is tuple:
        result += '<'
        for element in mset:
            result += get_multiset_math_form(element, _first=False)
        result += '>,'

    result = result.replace(",>", ">").replace(",}", "}")
    if _first:
        result = result[:-1]
    return result


def eprint(text: str):
    print(f"{__file__.split('/')[-1]}: error: {text}", file=sys.stderr)


def main():

    args = parse_args()

    if not check_args(args):
        eprint("one of the files was not found")
        exit(1)

    set_strs = []
    for file in args.files:
        set_strs.append(read_file(file))

    sets = {}
    for set_str in set_strs:
        name, mset = None, None

        try:
            name, mset = msl.parse(set_str)
        except SyntaxError as e:
            eprint(e.msg)
            exit(1)

        sets[name] = mset

    union = msl.Multiset()
    for aset in sets.values():
        union = union.union(aset)

    print(get_multiset_math_form(union))


if __name__ == "__main__":
    main()
