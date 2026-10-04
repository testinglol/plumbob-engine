
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall FUN_0045d060(int param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  float10 fVar3;
  
  iVar2 = FUN_004670a4(param_2);
  if (iVar2 == 0) {
    fVar3 = (float10)_DAT_0066657c;
  }
  else {
    cVar1 = FUN_00468851();
    if (cVar1 == '\0') {
      fVar3 = (float10)*(float *)(iVar2 + 0x68);
    }
    else {
      fVar3 = (float10)*(float *)(param_1 + 0x3c);
    }
  }
  return fVar3;
}

