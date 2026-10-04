
int __thiscall
FUN_0060b1b6(int *param_1,int param_2,int param_3,int param_4,char *param_5,uint param_6,
            int *param_7,int param_8,int param_9)

{
  uint uVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  char *pcVar5;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  uint local_c;
  char local_5;
  
  piVar2 = param_7;
  pcVar5 = param_5;
  if ((param_1[3] & 0x10U) == 0) {
    local_5 = '\0';
    if (*(char *)((int)param_1 + 0x22) == '\0') {
      cVar3 = FUN_0060bec0(param_2);
      if (cVar3 == '\0') {
        return 0;
      }
      *(undefined1 *)((int)param_1 + 0x22) = 1;
      local_5 = '\x01';
    }
    if (param_7 == (int *)0x0) {
      local_20 = *(int *)(param_2 + 0x14);
      local_1c = *(int *)(param_2 + 0x18);
      local_18 = *(int *)(param_2 + 0x1c);
      local_14 = *(int *)(param_2 + 0x20);
    }
    else {
      local_20 = *param_7;
      local_1c = param_7[1];
      local_18 = param_7[2];
      local_14 = param_7[3];
    }
    param_7 = (int *)param_3;
    if ((param_6 != 0) && (param_5 = (char *)0x0, param_6 != 0)) {
      do {
        cVar3 = *pcVar5;
        if (cVar3 == '\0') break;
        if (cVar3 != '\n') {
          local_10 = (**(code **)(*param_1 + 0x5c))(cVar3);
          if ((piVar2 == (int *)0x0) ||
             (((((int)param_7 < piVar2[2] && (param_4 < piVar2[3])) &&
               (*piVar2 <= local_10 + (int)param_7)) && (piVar2[1] <= param_1[6] + param_4)))) {
            uVar1 = local_c >> 8;
            local_c = local_c & 0xffffff00;
            if ((param_8 <= (int)param_5) && ((int)param_5 < param_9)) {
              local_c = CONCAT31((int3)uVar1,1);
            }
            FUN_0060bf16(param_2,param_7,param_4,*pcVar5,&local_20,local_c);
          }
          param_7 = (int *)((int)param_7 + local_10);
        }
        pcVar5 = pcVar5 + 1;
        param_5 = (char *)((int)param_5 + 1);
      } while (param_5 < param_6);
    }
    if (local_5 != '\0') {
      FUN_0060beeb(param_2);
      *(undefined1 *)((int)param_1 + 0x22) = 0;
    }
    iVar4 = (int)param_7 - param_3;
  }
  else {
    param_1[3] = param_1[3] & 0xffffffef;
    local_c = (**(code **)(*param_1 + 0x1c))();
    (**(code **)(*param_1 + 0x20))(0);
    iVar4 = (**(code **)(*param_1 + 0x78))
                      (param_2,param_3 + 2,param_4 + 2,param_5,param_6,param_7,param_8,param_9);
    (**(code **)(*param_1 + 0x20))(local_c);
    (**(code **)(*param_1 + 0x78))(param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
    param_1[3] = param_1[3] | 0x10;
    iVar4 = iVar4 + 2;
  }
  return iVar4;
}

