#!/usr/bin/env sh

cmd="$1"

projects="engine testbed"

if [ "$cmd" != "debug" ] && [ "$cmd" != "release" ] && [ "$cmd" != "clean" ]; then
    echo "Usage: $0 [debug|release|clean]"
    exit 1
fi

for project in $projects; do
    if [ -d "$project" ]; then
        cd "$project" || {
            echo "Failed to enter $project directory"
            exit 1
        }

        ./build.sh "$cmd"

        cd .. || exit 1
    else
        echo "Project directory '$project' not found"
        exit 1
    fi
done

