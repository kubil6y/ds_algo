function search(curr: BinaryNode<number> | null, needle: number): boolean {
    if (!curr) {
        return false;
    }
    if (curr?.value === needle) {
        return true;
    }
    if (curr?.value > needle) {
        return search(curr.left, needle);
    } else {
        return search(curr.right, needle);
    }
}

export default function dfs(root: BinaryNode<number>, needle: number): boolean {
    return search(root, needle);
}

/*
// alternative solution
export default function dfs(root: BinaryNode<number>, needle: number): boolean {
    const stack: BinaryNode<number>[] = [root];
    while (stack.length > 0) {
        const curr = stack.pop() as BinaryNode<number>;
        if (curr.value === needle) {
            return true;
        }
        if (curr.value > needle) {
            if (curr.left) {
                stack.push(curr.left);
            }
        } else {
            if (curr.right) {
                stack.push(curr.right);
            }
        }
    }
    return false;
}
*/
