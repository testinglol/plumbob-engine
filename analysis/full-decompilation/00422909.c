
void __fastcall FUN_00422909(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = (int *)(param_1 + 400);
  if (*(int *)(param_1 + 400) == 0) {
    iVar1 = *(int *)(param_1 + 0x18c);
    for (iVar2 = param_1; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x18c)) {
      *(int *)(iVar2 + 400) = iVar1;
    }
    if (iVar1 != 0) {
      *(undefined4 *)(iVar1 + 400) = 0;
    }
  }
  else {
    while (iVar1 = *piVar3, iVar1 != 0) {
      if (iVar1 == param_1) {
        *piVar3 = *(int *)(iVar1 + 0x18c);
      }
      else {
        piVar3 = (int *)(iVar1 + 0x18c);
      }
    }
  }
  *(int *)(param_1 + 400) = 0;
  *(undefined4 *)(param_1 + 0x18c) = 0;
  return;
}

