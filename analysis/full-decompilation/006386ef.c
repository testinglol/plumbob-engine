
byte * FUN_006386ef(byte *param_1)

{
  byte *pbVar1;
  
  pbVar1 = param_1 + 1;
  if ((*(byte *)((int)&DAT_00705240 + *param_1 + 1) & 4) != 0) {
    pbVar1 = param_1 + 2;
  }
  return pbVar1;
}

