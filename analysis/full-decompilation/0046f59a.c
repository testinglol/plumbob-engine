
uint FUN_0046f59a(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = FUN_0046f556();
  uVar2 = FUN_0046f556();
  uVar3 = uVar2 % param_1;
  if ((int)(uVar1 % param_1) < (int)(uVar2 % param_1)) {
    uVar3 = uVar1 % param_1;
  }
  uVar1 = FUN_0046f556();
  if ((uVar1 & 1) != 0) {
    uVar3 = -uVar3;
  }
  return uVar3;
}

