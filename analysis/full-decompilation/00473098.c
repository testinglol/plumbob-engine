
uint FUN_00473098(int param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = FUN_0046f973(param_1);
  if (uVar1 == 0) {
    iVar2 = FUN_0046f973(param_1 + 0x4c);
    uVar1 = CONCAT31((int3)((uint)-iVar2 >> 8),'\x01' - (iVar2 != 0));
  }
  else {
    uVar1 = uVar1 & 0xffffff00;
  }
  return uVar1;
}

