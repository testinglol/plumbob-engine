
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00513917(int *param_1,int param_2)

{
  int iVar1;
  float fVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  float10 fVar5;
  
  iVar1 = param_1[0x65];
  if (param_2 != iVar1) {
    (**(code **)(*param_1 + 0x168))();
    param_1[0x65] = param_2;
    if (param_2 - iVar1 < 1) {
      fVar5 = (float10)FUN_00513ade();
      uVar3 = FUN_00513857(0x405d5f,0xd10000,(float)fVar5);
      fVar2 = (float)(param_1[0x65] + 0x32) * _DAT_00667420;
      if (_DAT_0066657c <= fVar2) {
        if (_DAT_00666748 < fVar2) {
          fVar2 = 1.0;
        }
      }
      else {
        fVar2 = 0.0;
      }
      uVar4 = FUN_00513857(0x405d5f,0xca39,fVar2);
      FUN_0050c54c(uVar4,uVar4,0);
    }
    else {
      fVar5 = (float10)FUN_00513ade();
      uVar3 = FUN_00513857(0x405d5f,0xd10000,(float)fVar5);
      fVar2 = (float)(param_1[0x65] + 0x32) * _DAT_00667420;
      if (_DAT_0066657c <= fVar2) {
        if (_DAT_00666748 < fVar2) {
          fVar2 = 1.0;
        }
      }
      else {
        fVar2 = 0.0;
      }
      uVar4 = FUN_00513857(0x405d5f,0xca39,fVar2);
      FUN_0050c54c(uVar4,uVar4,0);
    }
    FUN_0050c54c(uVar3,uVar3,0);
  }
  return;
}

