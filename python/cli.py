#!/usr/bin/env python3

# This script showcases how to use argparse to create a simple command line
# script. In this example, we create a script that takes two numbers and
# adds them together.

import argparse


def main():
    parser = argparse.ArgumentParser(
        description="This is the description of this script. Enter two numbers and this script returns the addition of those numbers",
    )
    parser.add_argument(
        "number1",
        help="First number",
        type=float,
    )
    parser.add_argument(
        "number2",
        help="Second number",
        type=float,
    )
    parser.add_argument(
        "-v",
        "--verbose",
        dest="verbose",
        action="store_true",
        help="Adds verbosity to this script",
    )
    args = parser.parse_args()

    print(f"number1 + number 2 = {args.number1 + args.number2}")

    if args.verbose:
        print("This additional message comes if you enable verbosity")


if __name__ == "__main__":
    main()
