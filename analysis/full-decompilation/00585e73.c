
void __thiscall FUN_00585e73(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  int *piVar4;
  undefined1 local_24 [16];
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_14 = 0x7fffffff;
  local_10 = 0x7fffffff;
  local_c = 0x80000000;
  local_8 = 0x80000000;
  if (param_1[2] != 0) {
    iVar1 = FUN_00415707();
    iVar1 = iVar1 + 0xec;
    piVar4 = param_1 + 0xe;
    puVar3 = local_24;
    (**(code **)(*param_1 + 0xac))(puVar3,piVar4,iVar1);
    puVar2 = (undefined4 *)FUN_005a0af0(puVar3,piVar4,iVar1);
    local_14 = *puVar2;
    local_10 = puVar2[1];
    local_c = puVar2[2];
    local_8 = puVar2[3];
  }
  *param_2 = local_14;
  param_2[1] = local_10;
  param_2[2] = local_c;
  param_2[3] = local_8;
  return;
}

