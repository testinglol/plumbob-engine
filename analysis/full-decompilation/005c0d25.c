
int FUN_005c0d25(int param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = *(uint *)(param_1 + 0xc);
  uVar2 = *(uint *)(param_2 + 0xc);
  uVar3 = *(uint *)(param_3 + 0xc);
  if (uVar1 < uVar2) {
    if (uVar3 <= uVar2) {
      if (uVar3 <= uVar1) {
        return param_1;
      }
      return param_3;
    }
  }
  else {
    if (uVar1 < uVar3) {
      return param_1;
    }
    if (uVar2 < uVar3) {
      return param_3;
    }
  }
  return param_2;
}

