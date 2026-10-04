
uint __fastcall FUN_0043557a(int param_1)

{
  ushort uVar1;
  uint in_EAX;
  int iVar2;
  
  if ((*(byte *)(param_1 + 0xa0) & 0x10) == 0) {
    iVar2 = *(int *)(param_1 + 0x118);
    if (*(short *)(iVar2 + 0x12) != 2) {
      iVar2 = FUN_004573f9();
      in_EAX = *(uint *)(iVar2 + 0x60);
      if (*(short *)(in_EAX + 0x8a) != 0) goto LAB_004355ab;
      uVar1 = *(ushort *)(param_1 + 0xa0);
      iVar2 = CONCAT22((short)(in_EAX >> 0x10),uVar1);
      if ((uVar1 & 8) != 0) {
        return CONCAT31((int3)((uint)iVar2 >> 8),(byte)~(byte)uVar1 >> 4) & 0xffffff01;
      }
    }
    return CONCAT31((int3)((uint)iVar2 >> 8),1);
  }
LAB_004355ab:
  return in_EAX & 0xffffff00;
}

