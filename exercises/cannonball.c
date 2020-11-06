int cannonBallPyramid(int layers) {
  if(layers == 1) {
    return 1;
  }
  return (layers * layers) + cannonBallPyramid(layers - 1);
}
