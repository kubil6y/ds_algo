// https://stackoverflow.com/a/17384087
//
// NOTE: MAZE is a square
// BASE CASES
// 1. off the map
// 2. its a wall
// 3. its the end
// 4. already seen
//
// NOTE: Put logic in the base case as much as you can
// then complexity will go down.
const dir = [
    [-1, 0],
    [1, 0],
    [0, -1],
    [0, 1],
];

function walk(
    maze: string[],
    wall: string,
    curr: Point,
    end: Point,
    seen: boolean[][],
    path: Point[],
): boolean {
    // 1. off the map
    if (
        curr.x < 0 ||
        curr.x >= maze[0].length ||
        curr.y < 0 ||
        curr.y >= maze.length
    ) {
        return false;
    }

    // 2. its a wall
    if (maze[curr.y][curr.x] === wall) {
        return false;
    }

    // 3. its the end
    if (curr.x === end.x && curr.y === end.y) {
        path.push(end);
        return true;
    }

    // 4. already seen
    if (seen[curr.y][curr.x]) {
        return false;
    }

    // 3 recurse case {pre,recurse,post}
    // pre
    seen[curr.y][curr.x] = true;
    path.push(curr);

    // recurse
    for (let i = 0; i < dir.length; i++) {
        const [x, y] = dir[i];
        const newCurrent: Point = {
            x: curr.x + x,
            y: curr.y + y,
        };
        if (walk(maze, wall, newCurrent, end, seen, path)) {
            return true;
        }
    }

    // post
    path.pop();

    return false;
}

export default function solve(
    maze: string[],
    wall: string,
    start: Point,
    end: Point,
): Point[] {
    const seen: boolean[][] = [];
    const path: Point[] = [];

    for (let y = 0; y < maze.length; y++) {
        seen.push(new Array(maze[0].length).fill(false));
    }

    walk(maze, wall, start, end, seen, path);

    return path;
}
