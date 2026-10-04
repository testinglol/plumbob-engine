
undefined4 FUN_00614000(int *param_1,int param_2,int param_3,uint *param_4,int param_5)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (-1 < param_2) {
    iVar1 = *param_1;
    if (((param_2 < *(int *)(iVar1 + 0x10)) && (-1 < param_3)) && (param_3 < *(int *)(iVar1 + 0x14))
       ) {
      iVar2 = param_1[2] * param_3 + param_1[1];
      if (*(int *)(iVar1 + 0x18) < 9) {
        uVar3 = *(undefined4 *)(iVar1 + 0x28 + (uint)*(byte *)(iVar2 + param_2) * 4);
      }
      else {
        uVar3 = *(undefined4 *)(iVar2 + param_2 * 4);
      }
      if (param_5 != 0) {
        *param_4 = 1;
        return uVar3;
      }
      param_2._3_1_ = (char)((uint)uVar3 >> 0x18);
      *param_4 = (uint)(param_2._3_1_ != '\0');
      return uVar3;
    }
  }
  *param_4 = 0;
  return 0;
}

