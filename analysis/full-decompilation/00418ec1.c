
void __thiscall FUN_00418ec1(undefined4 *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)*param_1;
  do {
    if (piVar2 == (int *)param_1[1]) {
      return;
    }
    for (iVar1 = *piVar2; iVar1 != piVar2[1]; iVar1 = iVar1 + 0x5c) {
      if (iVar1 == param_2) {
        FUN_0041a757(iVar1);
        if ((piVar2[1] - *piVar2) / 0x5c != 0) {
          return;
        }
        FUN_0041a7fb(piVar2);
        return;
      }
    }
    piVar2 = piVar2 + 5;
  } while( true );
}

