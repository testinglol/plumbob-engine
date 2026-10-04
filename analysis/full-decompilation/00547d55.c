
void __fastcall FUN_00547d55(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x11c);
  if (iVar1 != -1) {
    iVar2 = FUN_004eacb7(iVar1);
    iVar3 = FUN_004ead68(iVar1);
    if (iVar3 == 0) {
      *(undefined4 *)(param_1 + 0x170) = 0xffffffff;
    }
    else if (*(int *)(param_1 + 0x170) < 0) {
      *(int *)(param_1 + 0x170) = 0;
    }
    else if (iVar3 <= *(int *)(param_1 + 0x170)) {
      *(int *)(param_1 + 0x170) = iVar3 + -1;
    }
    if (iVar2 == 0) {
      *(undefined4 *)(param_1 + 0x174) = 0xffffffff;
    }
    else if (*(int *)(param_1 + 0x174) < 0) {
      *(int *)(param_1 + 0x174) = 0;
    }
    else if (iVar2 <= *(int *)(param_1 + 0x174)) {
      *(int *)(param_1 + 0x174) = iVar2 + -1;
    }
  }
  FUN_004eacf0(iVar1,*(undefined4 *)(param_1 + 0x174));
  FUN_004eada1(iVar1,*(undefined4 *)(param_1 + 0x170));
  return;
}

