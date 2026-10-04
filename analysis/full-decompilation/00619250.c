
undefined4 FUN_00619250(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 local_10;
  undefined4 uStack_c;
  
  puVar1 = *(undefined4 **)(param_1 + 0x14);
  local_10 = 0;
  uStack_c = 0x40100000;
  if (puVar1 != (undefined4 *)0x0) {
    local_10 = *puVar1;
    uStack_c = puVar1[1];
  }
  iVar2 = __ftol();
  iVar2 = 3 - iVar2;
  iVar3 = FUN_005a9320(iVar2 * iVar2 * 8);
  if (iVar3 != 0) {
    FUN_00619310(iVar3,iVar2,local_10,uStack_c);
    FUN_00619470(param_3,param_4,*(undefined4 *)(*(int *)(param_1 + 0xc) + 4),
                 *(undefined4 *)(*(int *)(param_1 + 0xc) + 8),*(undefined4 *)(param_2 + 0x10),
                 *(undefined4 *)(param_2 + 0x14),iVar2,iVar3);
    FUN_005a9340(iVar3);
    return 1;
  }
  return 0;
}

