
undefined4 __thiscall
FUN_0045e707(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  char cVar1;
  short sVar2;
  undefined4 uVar3;
  int local_10;
  int local_c;
  char local_8;
  
  cVar1 = FUN_00452bd8(param_2,param_3,param_4,param_5);
  if (cVar1 == '\0') {
    uVar3 = 0;
  }
  else {
    local_10 = param_2;
    sVar2 = FUN_00475126();
    local_c = (int)sVar2;
    local_8 = (char)param_5;
    if (local_8 != '\0') {
      *(int *)(param_1 + 0xa54) = param_2;
    }
    FUN_0045fa7d(&local_10);
    *(short *)(param_2 + 0xc6) = *(short *)(param_2 + 0xc6) + 1;
    uVar3 = 1;
  }
  return uVar3;
}

