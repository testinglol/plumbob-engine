
void __thiscall FUN_004727bd(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined1 local_c [8];
  
  iVar3 = *param_1;
  iVar1 = (param_1[1] - iVar3) / 0x14;
  if (iVar3 != param_1[1]) {
    do {
      if (*(int *)(iVar3 + 0xc) == -1) {
        *(int *)(iVar3 + 0xc) = iVar1;
      }
      if (*(int *)(iVar3 + 0x10) == -1) {
        *(int *)(iVar3 + 0x10) = iVar1 + 1;
      }
      iVar3 = iVar3 + 0x14;
    } while (iVar3 != param_1[1]);
  }
  local_14 = 0xffffffff;
  local_10 = 0xffffffff;
  local_18 = 1;
  puVar2 = (undefined4 *)FUN_0047270c(local_c,param_2);
  local_20 = *puVar2;
  local_1c = puVar2[1];
  FUN_00472b86(&local_20);
  puVar2 = (undefined4 *)FUN_0047270c(local_c,param_3);
  local_20 = *puVar2;
  local_1c = puVar2[1];
  FUN_00472b86(&local_20);
  return;
}

