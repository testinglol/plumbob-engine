
void __fastcall FUN_005cedcb(int param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  iVar2 = __ftol();
  uVar3 = __ftol();
  uVar4 = __ftol();
  uVar5 = __ftol();
  uVar5 = ((iVar2 << 8 | uVar3) << 8 | uVar4) << 8 | uVar5;
  *(uint *)(param_1 + 0x1d0) = uVar5;
  piVar1 = *(int **)(*(int *)(param_1 + 0x60) + 0x38);
  (**(code **)(*piVar1 + 0x60))(piVar1,2,uVar5);
  return;
}

