
void __fastcall FUN_004011a0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  while( true ) {
    iVar1 = FUN_004015a1(uVar3);
    if (iVar1 == 0) break;
    puVar2 = (undefined4 *)FUN_004015a1(*(undefined4 *)(param_1 + 0xc));
    *puVar2 = 0xffffffff;
    if (*(int *)(param_1 + 0xc) <= *(int *)(param_1 + 8)) {
      *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
    }
    uVar3 = *(undefined4 *)(param_1 + 0xc);
  }
  return;
}

