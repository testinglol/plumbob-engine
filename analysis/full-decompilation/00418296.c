
void FUN_00418296(undefined4 *param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  
  do {
    if (param_1 == (undefined4 *)0x0) {
      return;
    }
    piVar1 = param_1 + 2;
    while (piVar2 = piVar1, piVar1 = (int *)*piVar2, piVar1 != (int *)0x0) {
      if (piVar1 == (int *)param_2) {
        piVar1 = (int *)*piVar2;
        *piVar2 = *piVar1;
        FUN_006321f0(piVar1);
        return;
      }
    }
    param_1 = (undefined4 *)*param_1;
  } while( true );
}

