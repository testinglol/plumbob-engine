
void __thiscall FUN_0042a970(int param_1,short param_2,short *param_3)

{
  int iVar1;
  int *piVar2;
  
  *param_3 = param_2;
  piVar2 = *(int **)(param_1 + 0x194);
  do {
    if (piVar2 == *(int **)(param_1 + 0x198)) {
LAB_0042a9c2:
      FUN_0042ec2b(&param_3);
      return;
    }
    if (*(short *)*piVar2 == param_2) {
      if (piVar2 != *(int **)(param_1 + 0x198)) {
        iVar1 = *piVar2;
        if (iVar1 != 0) {
          FUN_0041f37d();
          FUN_006321f0(iVar1);
        }
        *piVar2 = (int)param_3;
        return;
      }
      goto LAB_0042a9c2;
    }
    piVar2 = piVar2 + 1;
  } while( true );
}

