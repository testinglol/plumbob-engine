
LPARAM __thiscall FUN_005daa44(int param_1,int *param_2,int *param_3)

{
  undefined1 uVar1;
  int *piVar2;
  char cVar3;
  undefined4 uVar4;
  MSG local_34;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  LPARAM local_c;
  char local_5;
  
  local_c = -1;
  local_5 = '\0';
  local_10 = *(undefined4 *)(param_1 + 0x24);
  local_18 = *(undefined4 *)(param_1 + 0x28);
  if ((*(int **)(param_1 + 500) != (int *)0x0) &&
     (cVar3 = (**(code **)(**(int **)(param_1 + 500) + 0x8c))(1), cVar3 != '\0')) {
    local_5 = '\x01';
    (**(code **)(**(int **)(param_1 + 500) + 0x98))();
  }
  if (param_2 == (int *)0x0) {
    param_2 = *(int **)(param_1 + 0x2c);
  }
  if (*(int **)(param_1 + 0x174) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x174) + 0x10c))(0,0,param_3);
  }
  FUN_005d9c1b(param_3);
  local_14 = *(undefined4 *)(param_1 + 0x1c4);
  uVar1 = *(undefined1 *)(param_1 + 0x1c8);
  FUN_005dadbc(0,1);
  cVar3 = (**(code **)(*param_2 + 0x20))(param_3);
  if (cVar3 != '\0') {
    (**(code **)(*param_3 + 0x44))();
    piVar2 = *(int **)(param_1 + 0x20);
    if (((piVar2 != (int *)0x0) && (piVar2 != param_3)) &&
       ((**(code **)(*piVar2 + 0xa4))(), *(int **)(param_1 + 0x20) == piVar2)) {
      *(undefined4 *)(param_1 + 0x20) = 0;
    }
    *(int **)(param_1 + 0x28) = param_3;
    *(int **)(param_1 + 0x24) = param_3;
    (**(code **)(*param_3 + 0x138))();
    do {
      while( true ) {
        while (cVar3 = FUN_00604a0f(&local_34), cVar3 == '\0') {
          (**(code **)(**(int **)(param_1 + 0x48) + 0x3c))();
        }
        if (local_34.message == 0x12) {
          PostMessageA(local_34.hwnd,0x12,local_34.wParam,local_34.lParam);
          local_c = 0;
          goto LAB_005dab92;
        }
        if (local_34.message == 0x700) break;
        if ((DAT_006c9f92 == '\0') || (local_34.message != 0x3e4)) {
          TranslateMessage(&local_34);
          DispatchMessageA(&local_34);
        }
      }
    } while ((int *)local_34.wParam != param_3);
    local_c = local_34.lParam;
LAB_005dab92:
    (**(code **)(*param_3 + 0x13c))();
    FUN_005dadbc(local_14,uVar1);
    (**(code **)(*param_2 + 0x24))(param_3);
    *(undefined4 *)(param_1 + 0x28) = local_18;
    cVar3 = FUN_005da398(local_10);
    uVar4 = local_10;
    if (cVar3 == '\0') {
      uVar4 = *(undefined4 *)(param_1 + 0x28);
    }
    FUN_005d9884(uVar4);
    if (((piVar2 != (int *)0x0) && (piVar2 != param_3)) &&
       ((cVar3 = (**(code **)(*piVar2 + 0x8c))(0x100000), cVar3 != '\0' &&
        (*(int *)(DAT_006fe8f4 + 0x20) == 0)))) {
      *(int **)(DAT_006fe8f4 + 0x20) = piVar2;
    }
    if (*(int **)(param_1 + 0x1fc) != (int *)0x0) {
      (**(code **)(**(int **)(param_1 + 0x1fc) + 0x16c))();
    }
    if (local_5 != '\0') {
      (**(code **)(**(int **)(param_1 + 500) + 0x94))();
    }
  }
  return local_c;
}

