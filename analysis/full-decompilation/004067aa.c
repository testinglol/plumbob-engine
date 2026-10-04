
void __fastcall FUN_004067aa(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  iVar4 = 0;
  iVar3 = 0;
  FUN_004659fc(0);
  piVar5 = (int *)(param_1 + 0xc);
  do {
    if ((int *)*piVar5 == (int *)0x0) break;
    cVar1 = (**(code **)(*(int *)*piVar5 + 0x20))();
    if (cVar1 != '\0') {
      (**(code **)(*(int *)*piVar5 + 0x1c))();
      iVar2 = FUN_00401f6f();
      if ((iVar2 != 0) && (iVar3 == 0)) {
        iVar3 = iVar2;
      }
    }
    iVar4 = iVar4 + 1;
    piVar5 = piVar5 + 5;
  } while (iVar4 < 8);
  FUN_004659fc(iVar3);
  return;
}

