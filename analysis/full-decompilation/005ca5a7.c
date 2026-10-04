
int FUN_005ca5a7(undefined1 *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined1 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined1 local_978 [1024];
  undefined1 local_578 [1024];
  undefined1 auStack_178 [256];
  undefined4 local_78;
  undefined4 local_74;
  uint local_70;
  uint local_6c;
  int local_68;
  int local_54;
  int *local_8;
  
  iVar2 = (int)param_1;
  _memset(&local_78,0,0x6c);
  local_78 = 0x6c;
  local_74 = 0x1000;
  (**(code **)(**(int **)((int)param_1 + 4) + 0x58))(*(int **)((int)param_1 + 4),&local_78);
  iVar4 = (**(code **)(**(int **)((int)param_1 + 4) + 0x50))(*(int **)((int)param_1 + 4),&local_8);
  if (iVar4 == 0) {
    piVar1 = *(int **)(param_2 + 4);
    iVar4 = (**(code **)(*local_8 + 0x10))(local_8,0,0,0x100,local_578);
    if (iVar4 == 0) {
      iVar4 = (**(code **)(*piVar1 + 0x10))(piVar1,0,0,0x100,local_978);
      if (iVar4 == 0) {
        param_1 = local_578;
        iVar4 = 0;
        do {
          uVar3 = FUN_005ca569(param_1,local_978);
          param_1 = param_1 + 4;
          auStack_178[iVar4] = uVar3;
          iVar4 = iVar4 + 1;
        } while (iVar4 < 0x100);
        _memset(&local_78,0,0x6c);
        local_78 = 0x6c;
        iVar4 = (**(code **)(**(int **)(iVar2 + 4) + 100))(*(int **)(iVar2 + 4),0,&local_78,1,0);
        if (iVar4 == 0) {
          uVar6 = 0;
          if (local_70 != 0) {
            do {
              uVar5 = 0;
              iVar4 = local_68 * uVar6 + local_54;
              if (local_6c != 0) {
                do {
                  *(undefined1 *)(uVar5 + iVar4) = auStack_178[*(byte *)(uVar5 + iVar4)];
                  uVar5 = uVar5 + 1;
                } while (uVar5 < local_6c);
              }
              uVar6 = uVar6 + 1;
            } while (uVar6 < local_70);
          }
          (**(code **)(**(int **)(iVar2 + 4) + 0x80))(*(int **)(iVar2 + 4),0);
          (**(code **)(**(int **)(iVar2 + 4) + 0x7c))
                    (*(int **)(iVar2 + 4),*(undefined4 *)(param_2 + 4));
          iVar4 = 0;
        }
      }
    }
  }
  return iVar4;
}

