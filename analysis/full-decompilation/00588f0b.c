
float10 __thiscall FUN_00588f0b(int *param_1,undefined4 param_2)

{
  float fVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 0xf4))(param_2);
  if (iVar2 == 0) {
    fVar1 = 0.0;
  }
  else {
    fVar1 = *(float *)(iVar2 + 0x30);
  }
  return (float10)fVar1;
}

