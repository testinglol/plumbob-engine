
void __fastcall FUN_005c17b6(int *param_1)

{
  int iVar1;
  undefined1 uVar2;
  size_t sVar3;
  undefined4 local_c;
  int *local_8;
  
  iVar1 = *param_1;
  if (iVar1 == 0x2a2a2a2a) {
    local_c = param_1;
    local_8 = param_1;
    sVar3 = _strlen(&DAT_006d2b88);
    FUN_00412d8a(&DAT_006d2b88,&DAT_006d2b88 + sVar3);
  }
  else {
    local_8 = (int *)((uint)param_1 & 0xffffff00);
    local_c._0_3_ = (uint3)(byte)((uint)iVar1 >> 0x18) << 8;
    uVar2 = (undefined1)((uint)iVar1 >> 8);
    local_c = (int *)CONCAT13(uVar2,(int3)local_c);
    local_c = (int *)CONCAT31(local_c._1_3_,0x2e);
    local_c._0_3_ = CONCAT12((char)((uint)iVar1 >> 0x10),(undefined2)local_c);
    local_c = (int *)CONCAT13(uVar2,(int3)local_c);
    sVar3 = _strlen((char *)&local_c);
    FUN_00412d8a(&local_c,(int)&local_c + sVar3);
  }
  return;
}

