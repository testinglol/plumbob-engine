
int __thiscall FUN_00418e2d(undefined4 *param_1,int param_2,int *param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)*param_1;
  do {
    if (piVar2 == (int *)param_1[1]) {
      *param_3 = 0;
      return 0;
    }
    for (iVar1 = *piVar2; iVar1 != piVar2[1]; iVar1 = iVar1 + 0x5c) {
      if (*(int *)(iVar1 + 0xc) == param_2) {
        if (param_4 != 0) {
          piVar2[4] = param_4;
        }
        *param_3 = piVar2[3];
        return iVar1;
      }
    }
    piVar2 = piVar2 + 5;
  } while( true );
}

