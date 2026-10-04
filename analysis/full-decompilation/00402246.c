
uint __thiscall FUN_00402246(undefined4 *param_1,uint param_2)

{
  short sVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  short *psVar5;
  short local_18 [6];
  undefined4 *local_c;
  int local_8;
  
  local_c = param_1;
  local_18[0] = 2;
  local_18[1] = 0;
  local_18[2] = 3;
  local_18[3] = 0;
  local_18[4] = 1;
  local_18[5] = 0;
  local_8 = 0;
  psVar5 = local_18;
  while( true ) {
    sVar1 = *psVar5;
    uVar4 = 0;
    if (sVar1 == 0) {
      uVar4 = 0;
    }
    else if (sVar1 == 1) {
      uVar4 = 0x100;
    }
    else if (sVar1 == 2) {
      uVar4 = 0x1000;
    }
    else if (sVar1 == 3) {
      uVar4 = 0x2000;
    }
    piVar2 = (int *)(**(code **)*local_c)(uVar4);
    if ((piVar2 != (int *)0x0) &&
       (iVar3 = (**(code **)(*piVar2 + 0x3c))(0x42484156,param_2,0,0), iVar3 != 0)) break;
    local_8 = local_8 + 1;
    psVar5 = psVar5 + 2;
    if (2 < local_8) {
      local_8 = 0;
      psVar5 = local_18;
      while( true ) {
        sVar1 = *psVar5;
        uVar4 = 0;
        if (sVar1 == 0) {
          uVar4 = 0;
        }
        else if (sVar1 == 1) {
          uVar4 = 0x100;
        }
        else if (sVar1 == 2) {
          uVar4 = 0x1000;
        }
        else if (sVar1 == 3) {
          uVar4 = 0x2000;
        }
        piVar2 = (int *)(**(code **)*local_c)(uVar4);
        if ((piVar2 != (int *)0x0) &&
           (iVar3 = (**(code **)(*piVar2 + 0x3c))(0x42484156,param_2,0,1), iVar3 != 0)) break;
        local_8 = local_8 + 1;
        psVar5 = psVar5 + 2;
        if (2 < local_8) {
          return 0;
        }
      }
      param_2 = 0;
      (**(code **)(*piVar2 + 0x50))(iVar3,&param_2);
      return param_2 & 0xffff;
    }
  }
  param_2 = 0;
  (**(code **)(*piVar2 + 0x50))(iVar3,&param_2);
  return param_2 & 0xffff;
}

