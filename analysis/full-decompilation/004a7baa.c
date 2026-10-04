
void __thiscall
FUN_004a7baa(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int param_4,byte param_5,
            char param_6)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar5 = param_4;
  if (param_1[6] != param_4) {
    FUN_004a82db(param_4,0);
    FUN_004cefa3(iVar5,1);
  }
  cVar1 = FUN_004a7d04(&param_2);
  if ((cVar1 == '\0') && (param_1[0x1a] != 0)) {
    (**(code **)*param_1)(&param_4,param_2,param_3,param_1[6],DAT_006f0088,0);
    iVar6 = param_1[0x5d] + DAT_006f0084;
    iVar5 = param_1[0x5c] + DAT_006f0080;
    iVar8 = ((int)(param_1[0xc] - param_1[10]) / 2 - (int)param_4._2_2_) + iVar5;
    iVar7 = ((int)(param_1[0xd] - param_1[0xb]) / 2 - (int)(short)param_4) + iVar6;
    if (param_6 == '\0') {
      if (param_1[0x69] == 0) {
        FUN_004924ae(1);
        FUN_004c9d77(DAT_006c7778);
        FUN_004c9b93(iVar5,iVar8,iVar6,iVar7,param_5);
        *(undefined1 *)((int)param_1 + 0x17a) = 1;
        FUN_004b050c();
      }
      else {
        FUN_004924ae(1);
        FUN_004c9d77(DAT_006c7778);
        uVar2 = (uint)param_5;
        uVar3 = FUN_004c9cf3(iVar7,uVar2);
        uVar4 = FUN_004c9cba(iVar8,uVar3);
        FUN_004c9b93(uVar4,iVar8,uVar3,iVar7,uVar2);
      }
    }
    else {
      FUN_004a83dc(iVar8,iVar7,1);
    }
  }
  return;
}

