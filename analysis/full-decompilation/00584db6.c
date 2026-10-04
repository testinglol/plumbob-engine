
void __fastcall FUN_00584db6(int param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  
  piVar1 = (int *)(param_1 + 0xcc);
  uVar3 = 0;
  if (*(int *)(param_1 + 0xd0) - *piVar1 >> 2 != 0) {
    do {
      iVar2 = *(int *)(*piVar1 + uVar3 * 4);
      if (iVar2 != 0) {
        FUN_005836d2();
        FUN_006321f0(iVar2);
      }
      *(undefined4 *)(*piVar1 + uVar3 * 4) = 0;
      uVar3 = uVar3 + 1;
    } while (uVar3 < (uint)(*(int *)(param_1 + 0xd0) - *piVar1 >> 2));
  }
  FUN_0052ea87(*piVar1,*(undefined4 *)(param_1 + 0xd0));
  return;
}

