
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall FUN_005d3c15(int *param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  
  iVar3 = param_2;
  SetRect((LPRECT)(param_1 + 1),0x7fffffff,0x7fffffff,-0x80000000,-0x80000000);
  if ((param_3 == 0) || (param_3 == 2)) {
    uVar4 = (**(code **)(*param_1 + 0x18))();
    uVar5 = FUN_005cf73a(param_2,uVar4);
    if (uVar5 != 0) {
      if ((_DAT_006734a4 & uVar5) != 0) {
        (**(code **)(*param_1 + 0x20))();
        return 0;
      }
      param_2 = 2;
      goto LAB_005d3c74;
    }
  }
  param_2 = 1;
LAB_005d3c74:
  cVar1 = *(char *)(iVar3 + 0x66);
  *(undefined1 *)(iVar3 + 0x66) = 0;
  piVar7 = (int *)param_1[0x17];
  if (piVar7 != (int *)param_1[0x18]) {
    do {
      iVar2 = *piVar7;
      iVar6 = FUN_005cf6fc(iVar3,param_2);
      if (iVar6 != 0) {
        *(char *)(iVar3 + 0x66) = cVar1;
        return iVar6;
      }
      if ((*(int *)(iVar2 + 4) < *(int *)(iVar2 + 0xc)) &&
         (*(int *)(iVar2 + 8) < *(int *)(iVar2 + 0x10))) {
        FUN_00422698();
      }
      piVar7 = piVar7 + 1;
    } while (piVar7 != (int *)param_1[0x18]);
  }
  *(char *)(iVar3 + 0x66) = cVar1;
  if (((cVar1 != '\0') && (param_1[1] < param_1[3])) && (param_1[2] < param_1[4])) {
    FUN_005cf0fa(param_1 + 1);
  }
  return 0;
}

