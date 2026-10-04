
void __thiscall FUN_0050fb20(int *param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  float10 fVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  param_1[0x45] = param_3;
  if ((char)param_1[0x38] == '\0') {
    *(undefined1 *)(param_1 + 0x38) = 1;
    (**(code **)(*param_1 + 0x94))();
    FUN_0050fc6a(param_2);
    FUN_0050fcbb();
    uVar1 = DAT_006e5490;
    if ((char)param_1[0x44] == '\0') {
      FUN_005ddfdc(1);
      FUN_0057a7f7(s_UI_whoosh_006c7b60,0xfffffffc);
      FUN_004734bd(0,0x3f800000,0xfa,DAT_006e5490);
    }
    else {
      uVar5 = DAT_006e5490;
      FUN_00473496(DAT_006e5490);
      uVar2 = __ftol(uVar5);
      uVar4 = 0x3f800000;
      fVar3 = (float10)FUN_00473496(uVar1);
      FUN_004734bd((float)fVar3,uVar4,uVar2,uVar5);
      *(undefined1 *)(param_1 + 0x44) = 0;
    }
    (**(code **)(*param_1 + 0x168))();
  }
  return;
}

