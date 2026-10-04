
uint FUN_0043017f(void *param_1,size_t param_2,void *param_3,int param_4)

{
  size_t *psVar1;
  uint uVar2;
  size_t sVar3;
  size_t sVar4;
  size_t local_8;
  
  sVar3 = param_2 - (int)param_1;
  psVar1 = &param_2;
  sVar4 = param_4 - (int)param_3;
  local_8 = sVar3;
  if ((int)sVar3 <= (int)sVar4) {
    psVar1 = &local_8;
  }
  param_2 = sVar4;
  uVar2 = _memcmp(param_1,param_3,*psVar1);
  if (uVar2 == 0) {
    if ((int)sVar3 < (int)sVar4) {
      uVar2 = 0xffffffff;
    }
    else {
      uVar2 = (uint)((int)sVar4 < (int)sVar3);
    }
  }
  return uVar2;
}

