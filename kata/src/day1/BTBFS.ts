export default function bfs(root: BinaryNode<number>, needle: number): boolean {
    // When implementing a Breadth-First Search using an array list
    // will result in O(n2) because of shift/unshift. Always use a real queue.
    const q: BinaryNode<number>[] = [root]; // pretend its a real queue
    while (q.length !== 0) {
        const curr = q.shift() as BinaryNode<number>;
        if (curr.value === needle) {
            return true;
        }
        if (curr.left) {
            q.push(curr.left);
        }
        if (curr.right) {
            q.push(curr.right);
        }
    }
    return false;
}
