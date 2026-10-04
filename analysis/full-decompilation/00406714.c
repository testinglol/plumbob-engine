
int __fastcall FUN_00406714(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar2 = 0;
  FUN_004659fc(0);
  iVar4 = 0;
  piVar3 = (int *)(param_1 + 0xc);
  do {
    if ((int *)*piVar3 == (int *)0x0) {
      return iVar2;
    }
    iVar1 = (**(code **)(*(int *)*piVar3 + 0x18))();
    if (iVar1 != 0) {
      iVar2 = iVar1;
    }
    iVar4 = iVar4 + 1;
    piVar3 = piVar3 + 5;
  } while (iVar4 < 8);
  return iVar2;
}

