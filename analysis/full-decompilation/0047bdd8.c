
void FUN_0047bdd8(int param_1,int param_2,char param_3,byte param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uStack_1c;
  undefined4 local_8;
  
  local_8 = 0;
  iVar1 = *(int *)(param_1 + 8);
  if (0 < iVar1) {
    do {
      iVar3 = 0;
      do {
        uVar2 = FUN_0046f556();
        uStack_1c = uVar2 % (uint)param_4 + (int)param_3;
        if (uStack_1c < -0x80) {
          uStack_1c = -0x80;
        }
        else if (0x7f < uStack_1c) {
          uStack_1c = 0x7f;
        }
        *(char *)(*(int *)(*(int *)(param_1 + 0xc) + local_8 * 4) + iVar3) = (char)uStack_1c;
        iVar3 = iVar3 + param_2;
      } while (iVar3 < iVar1);
      local_8 = local_8 + param_2;
    } while (local_8 < iVar1);
  }
  return;
}

