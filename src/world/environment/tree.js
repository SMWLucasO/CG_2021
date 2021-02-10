World.environment.Tree = (function (three, world) {

    const settings = {
      treeTrunkMaterial: new three.MeshPhongMaterial({color: 0x594E2E}),
      treeLeafMaterial: new three.MeshPhongMaterial({color: 0x2A9E00}),
      treeGroundMaterial: new three.MeshPhongMaterial({color: 0x332D1A})
    };

    /**
     * Generate a tree
     * @param x {float} coordinate
     * @param y {float} coordinate
     * @param z {float} coordinate
     * @returns {Group}
     */
    const generateTree = function (x, y, z) {
        let tree = new three.Group();

        let treeTrunkMesh = generateTreeTrunk();
        tree.add(treeTrunkMesh)

        let leafMesh = generateTreeLeafs();
        leafMesh.position.set(treeTrunkMesh.position.x, treeTrunkMesh.position.y+3, treeTrunkMesh.position.z)
        tree.add(leafMesh);

        let groundMesh = generateTreeGround();
        groundMesh.position.set(treeTrunkMesh.position.x, treeTrunkMesh.position.y-2, treeTrunkMesh.position.z);
        tree.add(groundMesh);

        let groundSidesMesh = generateTreeGroundSides();
        groundSidesMesh.position.set(treeTrunkMesh.position.x, treeTrunkMesh.position.y-2, treeTrunkMesh.position.z);;
        tree.add(groundSidesMesh);

        tree.position.set(x,y,z);

        return tree;
    }

    /**
     * Generate the mesh representing the wood of the tree
     * @returns {Mesh}
     */
    const generateTreeTrunk = function () {
        let cyllGeometry = new three.CylinderGeometry(0.25,0.25,4);
        return new three.Mesh(cyllGeometry, settings.treeTrunkMaterial);
    }

    /**
     * Generate mesh representing the leafy part of a tree
     * @returns {Mesh}
     */
    const generateTreeLeafs = function () {
        let sphereGeometry = new three.SphereGeometry(2);
        return new three.Mesh(sphereGeometry, settings.treeLeafMaterial);
    }

    /**
     * Generate mesh for dirt ground around tree.
     * @returns {Mesh}
     */
    const generateTreeGround = function() {
        let circleGeometry = new three.CircleGeometry(.8, 32);
        circleGeometry.rotateX(Math.PI*1.5);

        let mesh = new three.Mesh(circleGeometry, settings.treeGroundMaterial);
        mesh.material.side = three.DoubleSide;

        return mesh;
    }

    /**
     * Generate a mesh for a small dirt bulge around the tree
     * @returns {Mesh}
     */
    const generateTreeGroundSides = function() {
        let torusGeometry = new three.TorusGeometry(.2);
        torusGeometry.rotateX(Math.PI*1.5);

        return new three.Mesh(torusGeometry, settings.treeGroundMaterial);
    }

    return {
        generateTree: generateTree
    };

})(THREE, World);