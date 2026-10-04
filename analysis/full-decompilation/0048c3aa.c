
void FUN_0048c3aa(int param_1)

{
  int *piVar1;
  
  piVar1 = DAT_006e5790;
  while( true ) {
    if (piVar1 == DAT_006e5794) {
      FUN_0048c47b(&param_1);
      return;
    }
    if (*piVar1 == param_1) break;
    piVar1 = piVar1 + 1;
  }
  return;
}

