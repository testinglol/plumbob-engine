
void FUN_005cbd40(uint *param_1,uint *param_2,int param_3)

{
  uint uVar1;
  
  for (; param_3 != 0; param_3 = param_3 + -1) {
    uVar1 = *param_1;
    param_1 = param_1 + 1;
    *param_2 = uVar1 & 0xc0000000;
    param_2 = param_2 + 1;
  }
  return;
}

