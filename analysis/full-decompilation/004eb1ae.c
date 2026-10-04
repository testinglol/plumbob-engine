
undefined4 FUN_004eb1ae(undefined4 param_1)

{
  short sVar1;
  short sVar2;
  undefined2 *puVar3;
  undefined4 local_8;
  
  local_8 = 0;
  puVar3 = (undefined2 *)FUN_004ea2ce(param_1);
  FUN_0042a8e3(*puVar3);
  sVar1 = FUN_0041f662(7,0x1fec6005,&local_8);
  sVar2 = FUN_0041f662(7,0xc522329f,&local_8);
  return CONCAT31((int3)((uint)((int)sVar2 + (int)sVar1) >> 8),(int)sVar2 + (int)sVar1 != 0);
}

