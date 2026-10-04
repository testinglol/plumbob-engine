
undefined4 FUN_0056f815(byte *param_1,uint *param_2)

{
  byte *pbVar1;
  int iVar2;
  undefined4 local_8;
  
  pbVar1 = param_1;
  iVar2 = FUN_0056f209(0);
  if ((*pbVar1 & 2) == 0) {
    *param_2 = (uint)(byte)(&DAT_006f6285)[iVar2 * 2];
    param_1 = (byte *)((byte)(&DAT_006f6284)[iVar2 * 2] + 0x100);
  }
  else {
    *param_2 = (uint)(byte)(&DAT_006f62a5)[iVar2 * 2];
    param_1 = (byte *)(uint)(byte)(&DAT_006f62a4)[iVar2 * 2];
  }
  local_8 = 0;
  FUN_005d2475(&param_1,&local_8);
  return local_8;
}

