
uint __thiscall FUN_0063411f(int *param_1,int param_2)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_10;
  int local_c;
  uint local_8;
  
  iVar5 = 0;
  local_c = 0;
  local_10 = 1;
  uVar2 = *(uint *)(*(int *)(*param_1 + 4) + 0x24 + (int)param_1);
  if ((uVar2 & 0x10) == 0) {
    if ((uVar2 & 0x40) == 0) {
      local_8 = ((int)(char)uVar2 & 0x20U) >> 2;
    }
    else {
      local_8 = 0x10;
    }
  }
  else {
    local_8 = 10;
  }
  iVar3 = FUN_006327fb(0);
  if (iVar3 != 0) {
    iVar3 = FUN_006340b6();
    while (iVar3 != -1) {
      if ((iVar5 == 0) && ((iVar3 == 0x2d || (iVar3 == 0x2b)))) {
        local_10 = local_10 + 1;
      }
      else if ((iVar5 == local_10) && (*(char *)(iVar5 + -1 + param_2) == '0')) {
        if (((iVar3 != 0x78) && (iVar3 != 0x58)) || ((local_8 != 0 && (local_8 != 0x10)))) {
          if (local_8 != 0) goto LAB_0063421a;
          local_8 = 8;
          goto LAB_006341d3;
        }
        local_8 = 0x10;
        local_c = 0;
      }
      else {
LAB_0063421a:
        if (local_8 == 0x10) {
          iVar4 = FUN_006368eb(iVar3);
          if (iVar4 == 0) goto LAB_0063423b;
        }
        else {
LAB_006341d3:
          iVar4 = FUN_006368c3(iVar3);
          if ((iVar4 == 0) || ((local_8 == 8 && (0x37 < iVar3)))) goto LAB_0063423b;
        }
        local_c = local_c + 1;
      }
      *(char *)(iVar5 + param_2) = (char)iVar3;
      iVar3 = FUN_00633ffa();
      iVar5 = iVar5 + 1;
      if (0xe < iVar5) goto LAB_0063423b;
    }
    puVar1 = (uint *)(*(int *)(*param_1 + 4) + 8 + (int)param_1);
    *puVar1 = *puVar1 | 1;
LAB_0063423b:
    if (local_c == 0) {
      puVar1 = (uint *)(*(int *)(*param_1 + 4) + 8 + (int)param_1);
      *puVar1 = *puVar1 | 2;
      while (iVar5 != 0) {
        iVar3 = FUN_005c4410(*(undefined1 *)(iVar5 + -1 + param_2));
        puVar1 = (uint *)(*(int *)(*param_1 + 4) + 8 + (int)param_1);
        if (iVar3 == -1) {
          *puVar1 = *puVar1 | 4;
          break;
        }
        *puVar1 = *puVar1 & 0xfffffffe;
        iVar5 = iVar5 + -1;
      }
      iVar5 = 0;
    }
    *(undefined1 *)(iVar5 + param_2) = 0;
    FUN_00632716();
    param_2 = iVar5;
  }
  if (param_2 == 0x10) {
    puVar1 = (uint *)(*(int *)(*param_1 + 4) + 8 + (int)param_1);
    *puVar1 = *puVar1 | 2;
  }
  return local_8;
}

