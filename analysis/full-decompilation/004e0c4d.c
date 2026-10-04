
void FUN_004e0c4d(int param_1)

{
  BOOL BVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined1 local_110;
  undefined4 local_10f;
  undefined4 local_c;
  undefined4 local_8;
  
  FUN_004e0eba(s_Call_stack__006c95b4);
  FUN_004e0eba(s_Address_Frame_Logical_addr_Modul_006c9588);
  uVar5 = *(undefined4 *)(param_1 + 0xb8);
  puVar3 = *(undefined4 **)(param_1 + 0xb4);
  local_8 = 0;
  local_110 = DAT_006de560;
  puVar4 = &local_10f;
  for (iVar2 = 0x40; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  *(undefined2 *)puVar4 = 0;
  *(undefined1 *)((int)puVar4 + 2) = 0;
  param_1 = 0;
  FUN_004e0bbc(uVar5,&local_110,0x104,&local_8,&param_1);
  while( true ) {
    FUN_004e0eba(s__08X__08X__04X__08X__s_006c956c,uVar5,puVar3,local_8,param_1,&local_110);
    local_c = puVar3[1];
    puVar4 = (undefined4 *)*puVar3;
    if ((((uint)puVar4 & 3) != 0) || (puVar4 <= puVar3)) break;
    BVar1 = IsBadWritePtr(puVar4,8);
    if (BVar1 != 0) {
      return;
    }
    local_110 = DAT_006de560;
    puVar3 = &local_10f;
    for (iVar2 = 0x40; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    *(undefined2 *)puVar3 = 0;
    *(undefined1 *)((int)puVar3 + 2) = 0;
    local_8 = 0;
    param_1 = 0;
    FUN_004e0bbc(local_c,&local_110,0x104,&local_8,&param_1);
    puVar3 = puVar4;
    uVar5 = local_c;
  }
  return;
}

