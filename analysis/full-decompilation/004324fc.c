
void FUN_004324fc(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  
  iVar1 = FUN_00432539(param_1,param_2);
  while( true ) {
    if (iVar1 == 0) {
      return;
    }
    uVar3 = (uint)*(short *)(iVar1 + 0x5a);
    if ((uVar3 >> 2 & 1) == 0) {
      bVar2 = (byte)(uVar3 >> 4);
    }
    else {
      bVar2 = ~(byte)(uVar3 >> 1);
    }
    if ((bVar2 & 1) == 0) break;
    iVar1 = FUN_004328d2(0);
  }
  return;
}

