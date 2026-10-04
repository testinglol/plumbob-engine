
void __thiscall FUN_0043206d(int *param_1,int param_2)

{
  undefined4 uVar1;
  short sVar2;
  undefined4 uVar3;
  int *piVar4;
  char local_24 [4];
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  short local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if (param_2 == 0) {
    FUN_00457da4();
    sVar2 = FUN_004561a0(3);
    if (sVar2 == 0) {
      local_c = 0;
      local_8 = 0;
      local_20 = 0;
      local_1c = 0;
      FUN_00432664(local_24);
      local_c = local_20;
      local_8 = local_1c;
      (**(code **)(*param_1 + 0x50))(1);
      if (((uint)param_1[0x45] >> 6 & 1) == 0) {
        (**(code **)(*param_1 + 0x40))(1);
        if (local_24[0] != '\0') {
          (**(code **)(*param_1 + 0x58))(&local_c,local_10,local_18,(int)local_14,1);
        }
      }
    }
    else {
      FUN_00422d79(3,0,0);
      *(byte *)((int)param_1 + 0x5a) = *(byte *)((int)param_1 + 0x5a) & 0xdf;
      *(undefined2 *)((int)param_1 + 0xc6) = 0;
      FUN_00457da4();
      uVar1 = *(undefined4 *)(param_1[0x47] + 0xc);
      uVar3 = FUN_004561a0(1);
      FUN_00474979(uVar1,uVar3);
    }
    FUN_00431e78((int)(short)param_1[0x3c],0xffffffff);
    if (*(int *)(DAT_006e486c + 0x10) != 0) {
      FUN_0057a9a6((int)(short)param_1[0x3c]);
    }
    piVar4 = (int *)FUN_00444bf6();
    if (piVar4 == param_1) {
      FUN_00444c08(0);
    }
  }
  return;
}

