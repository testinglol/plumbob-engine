
undefined1 __thiscall FUN_004cbc88(int param_1,int param_2)

{
  undefined1 uVar1;
  char cVar2;
  undefined4 uVar3;
  
  if (*(int *)(param_1 + 0x24) == 1) {
    switch(param_2) {
    default:
      goto LAB_004cbce7;
    case 1:
      uVar3 = 9;
      break;
    case 2:
      uVar3 = 8;
      break;
    case 4:
      uVar3 = 5;
      break;
    case 5:
      uVar3 = 7;
      break;
    case 6:
      uVar3 = 6;
      break;
    case 8:
      uVar3 = 3;
      break;
    case 9:
      uVar3 = 4;
    }
    uVar1 = FUN_00487d5b(*(undefined4 *)(param_1 + 0x28),uVar3);
  }
  else {
    if (param_2 == *(int *)(param_1 + 0x38)) {
      if (param_2 == 7) {
        cVar2 = FUN_004a15b1(*(undefined4 *)(param_1 + 0x44));
        return cVar2 != '\0';
      }
      return true;
    }
LAB_004cbce7:
    uVar1 = 0;
  }
  return uVar1;
}

