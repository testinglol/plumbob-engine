
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0063a8a3(char *param_1)

{
  undefined4 uVar1;
  size_t sVar2;
  size_t sVar3;
  undefined4 uVar4;
  
  uVar4 = 0xffffffff;
  FUN_0063cf0c(1,&DAT_006dae50);
  uVar1 = FUN_0063e397(&DAT_006dae50);
  sVar2 = _strlen(param_1);
  sVar3 = FUN_006360de(param_1,1,sVar2,&DAT_006dae50);
  if (sVar3 == sVar2) {
    _DAT_006dae54 = _DAT_006dae54 + -1;
    if (_DAT_006dae54 < 0) {
      FUN_006411ee(10,&DAT_006dae50);
    }
    else {
      *DAT_006dae50 = 10;
      DAT_006dae50 = DAT_006dae50 + 1;
    }
    uVar4 = 0;
  }
  FUN_0063e424(uVar1,&DAT_006dae50);
  FUN_0063cf5e(1,&DAT_006dae50);
  return uVar4;
}

