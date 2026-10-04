
undefined4 __thiscall FUN_00589ef7(int *param_1,undefined4 param_2,char param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined *puVar5;
  
  uVar1 = FUN_00589fd2();
  iVar2 = FUN_00592602(param_2,uVar1);
  if (iVar2 != -1) {
    if ((char)param_1[0x36] != '\0') {
      *(char *)(param_1 + 0x36) = '\0';
      (**(code **)(*param_1 + 0x14))();
    }
    iVar2 = FUN_0059db5f(param_1[0x4e],iVar2);
    if (iVar2 != 0) {
      FUN_004071be(param_1[0xb],param_1[0xc]);
      iVar3 = (**(code **)(*param_1 + 0x100))(param_1 + 3,iVar2,param_3 == '\0');
      if (iVar3 != 0) {
        param_1[0x26] = -1;
        param_1[100] = 0;
        param_1[0x69] = 1;
        return 1;
      }
      if (DAT_006f29f4 != '\0') {
        if (*(int *)(iVar2 + 8) == *(int *)(iVar2 + 4)) {
          pcVar4 = s__unnamed_skill__006d0590;
        }
        else {
          pcVar4 = *(char **)(iVar2 + 4);
        }
        puVar5 = &DAT_006d0dac;
        FUN_005bc69b(s_Could_not_start_reach_animation_006d0d88);
        FUN_005bc69b(pcVar4);
        FUN_005bc69b(puVar5);
      }
    }
  }
  return 0;
}

