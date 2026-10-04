
uint __thiscall FUN_004cbb7d(int param_1,uint param_2)

{
  short sVar1;
  uint in_EAX;
  uint uVar2;
  
  if (*(int *)(param_1 + 0x24) == 1) {
    sVar1 = *(short *)(*(int *)(*(int *)(param_1 + 0x28) + 0x60) + 0xc2);
    uVar2 = CONCAT31((int3)(char)((ushort)sVar1 >> 8),(param_2 & (int)sVar1) != 0);
  }
  else {
    uVar2 = in_EAX & 0xffffff00;
  }
  return uVar2;
}

